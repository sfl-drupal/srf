<?php

/**
 * Helper function to clean customized field label,
 * to print it in an error message
 * @param  string $srf_label Label to be cleaned
 */
function _srf_clean_field_label($srf_label) {
  return str_replace(' *', '', strip_tags($srf_label));
}

/**
 * Helper function to print publication warning on a field.
 * @param  string $field_name  Field machine name
 * @param  string $field_label Field (instance) label
 */
function _srf_print_field_warning($field_name, $field_label, $new_status) {
  form_set_error($field_name, t('Field <strong>@field_label</strong> is required to pass this content as: <strong>@new_status</strong>.', array('@field_label' => $field_label, '@new_status' => $new_status)));
}

/**
 * Callback function to check filling different fields.
 * types of fields: text, text_long, date
 */
function srf_field_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (!$field_values[0]['value']) {
    $field_label = _srf_clean_field_label($element['#title']);
    _srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Callback function to check filling entityreference fields.
 */
function srf_entityreference_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['target_id']['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (!$field_values[0]['target_id']) {
    $field_label = _srf_clean_field_label($element['target_id']['#title']);
    _srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Callback function to check filling taxonomy_term_reference fields.
 */
function srf_taxonomy_term_reference_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (empty($field_values) || $field_values[0]['tid']== NULL) {
    $field_label = _srf_clean_field_label($element['#title']);
    _srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Callback function to check filling file or image fields.
 *
 * For file or image field, we must pass the arguments with a default value as NULL
 * and then check if they are not null, because we want to call this validate
 * function only when form is submitted (but not when «Upload» button is clicked).
 */
function srf_file_validate($element, &$form_state = NULL, $form = NULL, $new_status = NULL) {

  if ($element && $form_state && $form && $new_status) {

    // If $element is directly the field
    if (isset($element['#field_name'])) {
      _srf_helper_file_validate($element, $form_state, $form, $new_status);
    }

    // It may be an array of fields, so we have to iterate
    else {
      foreach ($element as $delta => &$elem) {
        _srf_helper_file_validate($element[$delta], $form_state, $form, $new_status);
      }
    }
  }
}

function _srf_helper_file_validate(&$element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (!$field_values[0]['fid']) {
    $field_label = _srf_clean_field_label($element['#title']);
    _srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Callback function to check filling image fields.
 */
function srf_link_field_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (!$field_values[0]['url']) {
    $field_label = _srf_clean_field_label($element['#title']);
    _srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Callback function to check filling email fields.
 */
function srf_email_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (!$field_values[0]['email']) {
    $field_label = _srf_clean_field_label($element['#title']);
    _srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

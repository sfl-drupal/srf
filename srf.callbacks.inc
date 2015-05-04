<?php

/**
 * Helper function to add the srf validate function to the field element.
 * @param  array  $validate_receiver Element which you need to add validate function
 * @param  string $validate_function Validate function name
 */
function srf_add_validate_function(&$validate_receiver, $validate_function) {
  if (isset($validate_receiver['#element_validate'])
    && is_array($validate_receiver['#element_validate'])) {
    $validate_receiver['#element_validate'][] = $validate_function;
  }
  else {
    $validate_receiver['#element_validate'] = array($validate_function);
  }
}

/**
 * Callback function to alter text_long widget.
 * @param  array $element Element to be altered
 */
function srf_text_long_alter_widget(&$element) {
  $element['value']['#title'] = theme('srf_field_label', array(
    'title' => $element['value']['#title'],
    ));
  srf_add_validate_function($element['value'], 'srf_text_long_validate');
}

/**
 * Callback function to alter text_with_summary widget.
 * @param  array $element Element to be altered
 */
function srf_text_with_summary_alter_widget(&$element) {
  $element['#title'] = theme('srf_field_label', array(
    'title' => $element['#title'],
    ));
  srf_add_validate_function($element, 'srf_text_with_summary_validate');
}

/**
 * Callback function to alter entityreference widget.
 * @param  array $element Element to be altered
 */
function srf_entityreference_alter_widget(&$element) {
  $element['target_id']['#title'] = theme('srf_field_label', array(
    'title' => $element['target_id']['#title'],
    ));
  srf_add_validate_function($element, 'srf_entityreference_validate');
}

/**
 * Callback function to alter taxonomy_term_reference widget.
 * @param  array $element Element to be altered
 */
function srf_taxonomy_term_reference_alter_widget(&$element) {
  $element['#title'] = theme('srf_field_label', array(
    'title' => $element['#title'],
    ));
  srf_add_validate_function($element, 'srf_taxonomy_term_reference_validate');
}

/**
 * Callback function to alter image widget.
 * @param  array $element Element to be altered
 */
function srf_image_alter_widget(&$element) {
  foreach ($element as $id => &$elem) {
    $elem['#title'] = theme('srf_field_label', array(
      'title' => $elem['#title'],
      ));
    srf_add_validate_function($elem, 'srf_image_validate');
  }
}

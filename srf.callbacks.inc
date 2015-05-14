<?php

/**
 * Callback function to alter titles of differents field widgets.
 * types of fields: text, text_long, taxonomy_term_reference, date, link_field
 * @param  array $element Element to be altered
 */
function srf_field_alter_widget(&$element) {
  $element['#title'] = theme('srf_field_label', array(
    'title' => $element['#title'],
  ));
}

/**
 * Callback function to alter entityreference widget.
 * @param  array $element Element to be altered
 */
function srf_entityreference_alter_widget(&$element) {
  srf_field_alter_widget($element);
  $element['target_id']['#title'] = theme('srf_field_label', array(
    'title' => $element['target_id']['#title'],
  ));
}

/**
 * Callback function to alter file or image widget.
 * @param  array $element Element to be altered
 */
function srf_file_alter_widget(&$element) {
  if (isset($element['#title'])) {
    _alter_title_widget($element);
  }
  else {
    foreach ($element as $id => &$elem) {
      if (isset($elem['#title'])) {
        _alter_title_widget($elem);
      }
    }
  }
}

/**
 * Callback function to alter email widget.
 * @param  array $element Element to be altered
 */
function srf_email_alter_widget(&$element) {
  srf_field_alter_widget($element);
  $element['email']['#title'] = theme('srf_field_label', array(
    'title' => $element['email']['#title'],
  ));
}
